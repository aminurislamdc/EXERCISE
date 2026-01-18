#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#endif

class WeatherSystem {
private:
    std::vector<std::string> weatherConditions;

public:
    WeatherSystem() {
        weatherConditions = {"Sunny", "Cloudy", "Rainy", "Foggy", "Heavy Rain", "Stormy"};
        srand(static_cast<unsigned int>(time(NULL)));
    }

    double getWeatherImpact(const std::string& condition) {
        if (condition == "Sunny") return 1.0;
        if (condition == "Cloudy") return 1.05;
        if (condition == "Rainy") return 1.25;
        if (condition == "Foggy") return 1.15;
        if (condition == "Heavy Rain") return 1.45;
        if (condition == "Stormy") return 1.6;
        return 1.0;
    }

    std::string getRandomWeather() {
        int index = rand() % weatherConditions.size();
        return weatherConditions[index];
    }

    std::string getWeatherColor(const std::string& condition) {
        if (condition == "Sunny") return "🟡";
        if (condition == "Cloudy") return "⚪";
        if (condition == "Rainy") return "🔵";
        if (condition == "Foggy") return "🌫️";
        if (condition == "Heavy Rain") return "🔵";
        if (condition == "Stormy") return "🟣";
        return "⚪";
    }
};

struct SegmentInfo {
    std::string from;
    std::string to;
    double distance;
    double traffic;
    double timeFactor;
    double weatherImpact;
    double fare;
    std::string trafficColor;
    int travelTime;
};

class DhakaBusSystem {
private:
    std::map<std::string, std::pair<double, double>> places;
    std::map<std::string, std::vector<std::pair<std::string, double>>> graph;
    WeatherSystem weatherSystem;
    std::string currentWeather;
    const double BASE_FARE_PER_KM = 2.45;

public:
    DhakaBusSystem() {
        currentWeather = weatherSystem.getRandomWeather();
        loadLocationsFromFile();
        buildGraph();
        std::cout << "🚌 Dhaka Bus System Initialized!\n";
        std::cout << "💰 Fare Rate: " << BASE_FARE_PER_KM << " per km (Direct Distance)\n";
        std::cout << "🌤️  Current Weather: " << currentWeather << "\n\n";
    }

    void loadLocationsFromFile() {
        std::ifstream file("locations.txt");

        if (!file.is_open()) {
            std::cout << "⚠️ Error: locations.txt file pawa jacche na! Program bondho hoye jabe.\n";
            return;
        }

        std::string name;
        double lat, lon;
        int count = 0;

        while (file >> name >> lat >> lon) {
            places[name] = std::make_pair(lat, lon);
            count++;
        }

        std::cout << "📂 File theke " << count << " ti location load kora hoyeche.\n";
        file.close();
    }

    double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
        const double R = 6371.0;
        double dLat = (lat2 - lat1) * 3.14159 / 180.0;
        double dLon = (lon2 - lon1) * 3.14159 / 180.0;

        double a = sin(dLat/2) * sin(dLat/2) +
                   cos(lat1 * 3.14159/180.0) * cos(lat2 * 3.14159/180.0) * sin(dLon/2) * sin(dLon/2);
        double c = 2 * atan2(sqrt(a), sqrt(1-a));
        return R * c;
    }

    void buildGraph() {
        std::cout << "🔄 Building route network...";
        graph.clear();
        for (auto& A : places) {
            for (auto& B : places) {
                if (A.first != B.first) {
                    double dist = calculateDistance(A.second.first, A.second.second,
                                                  B.second.first, B.second.second);
                    if (dist < 5.0) {
                        graph[A.first].push_back(std::make_pair(B.first, dist));
                    }
                }
            }
        }
        std::cout << " ✅ Done! (" << graph.size() << " locations connected)\n";
    }

    std::vector<std::string> findShortestPath(const std::string& start, const std::string& end) {
        if (places.find(start) == places.end() || places.find(end) == places.end()) {
            return std::vector<std::string>();
        }

        std::map<std::string, double> dist;
        std::map<std::string, std::string> prev;

        for (auto& place : places) {
            dist[place.first] = 1e18;
        }
        dist[start] = 0;

        using Pair = std::pair<double, std::string>;
        std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
        pq.push(std::make_pair(0, start));

        while (!pq.empty()) {
            Pair top = pq.top();
            double currentDist = top.first;
            std::string u = top.second;
            pq.pop();

            if (u == end) break;
            if (currentDist > dist[u]) continue;

            if (graph.find(u) != graph.end()) {
                for (auto& edge : graph[u]) {
                    std::string v = edge.first;
                    double weight = edge.second;

                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        prev[v] = u;
                        pq.push(std::make_pair(dist[v], v));
                    }
                }
            }
        }

        std::vector<std::string> path;
        if (dist[end] >= 1e18) {
            return path;
        }

        std::string current = end;
        while (current != start) {
            path.insert(path.begin(), current);
            if (prev.find(current) == prev.end()) break;
            current = prev[current];
        }
        path.insert(path.begin(), start);

        return path;
    }

    double getTrafficFactor() {
        time_t now = time(0);
        struct tm* timeinfo = localtime(&now);
        int hour = timeinfo->tm_hour;

        double baseTraffic;
        if ((hour >= 8 && hour < 10) || (hour >= 17 && hour < 19)) {
            baseTraffic = 1.4;
        } else if (hour >= 23 || hour < 6) {
            baseTraffic = 1.0;
        } else {
            baseTraffic = 1.2;
        }

        return baseTraffic + (rand() % 20) / 100.0;
    }

    std::string getTrafficColor(double traffic) {
        if (traffic > 1.5) return "🔴";
        if (traffic > 1.3) return "🟠";
        if (traffic > 1.1) return "🟡";
        return "🟢";
    }

    double getTimeFactor() {
        time_t now = time(0);
        struct tm* timeinfo = localtime(&now);
        int hour = timeinfo->tm_hour;

        if (hour >= 23 || hour < 6) return 1.25;
        if ((hour >= 8 && hour < 10) || (hour >= 17 && hour < 20)) return 1.15;
        return 1.0;
    }

    void updateWeather() {
        currentWeather = weatherSystem.getRandomWeather();
        std::cout << "🌤️  Weather Updated: " << weatherSystem.getWeatherColor(currentWeather)
                  << " " << currentWeather << "\n";
    }

    void addNewPlace() {
        std::string name;
        double lat, lon;

        std::cout << "\n➕ ADD NEW PLACE\n";
        std::cout << "Enter place name (No spaces, e.g., Rampura): ";
        std::cin >> name;

        if (places.find(name) != places.end()) {
            std::cout << "❌ Place already exists!\n";
            return;
        }

        std::cout << "Enter latitude (e.g., 23.7310): ";
        std::cin >> lat;
        std::cout << "Enter longitude (e.g., 90.4175): ";
        std::cin >> lon;

        places[name] = std::make_pair(lat, lon);

        std::ofstream file("locations.txt", std::ios::app);
        if (file.is_open()) {
            file << name << " " << lat << " " << lon << "\n";
            file.close();
            std::cout << "💾 Saved to locations.txt successfully!\n";
        } else {
            std::cout << "⚠️ Error: Could not save to file!\n";
        }

        buildGraph();
        std::cout << "✅ Place '" << name << "' added and saved!\n";
    }

    void openOnlineMap() {
        int mapChoice;
        std::cout << "\n" << std::string(30, '-') << "\n";
        std::cout << "     🌏 ONLINE MAP TOOLS\n";
        std::cout << std::string(30, '-') << "\n";
        std::cout << "1. 📍 Show My Live Device Location\n";
        std::cout << "2. 🔍 View a Specific Place on Map\n";
        std::cout << "3. 🗺️  View Route on Map (Start -> End)\n";
        std::cout << "4. 🔙 Back\n";
        std::cout << "Select option: ";
        std::cin >> mapChoice;

        std::string url;

        if (mapChoice == 1) {
            url = "https://www.google.com/maps";
            std::cout << "🚀 Opening Google Maps for Live Location...\n";
            std::string command = "start " + url;
            system(command.c_str());
        }
        else if (mapChoice == 2) {
            showAllPlaces();
            std::string name;
            std::cout << "Enter place name to view: ";
            std::cin >> name;

            if (places.find(name) != places.end()) {
                double lat = places[name].first;
                double lon = places[name].second;
                url = "https://www.google.com/maps/search/?api=1&query=" +
                      std::to_string(lat) + "," + std::to_string(lon);

                std::cout << "🚀 Opening Map for " << name << "...\n";
                std::string command = "start " + url;
                system(command.c_str());
            } else {
                std::cout << "❌ Place not found in system!\n";
            }
        }
        else if (mapChoice == 3) {
            std::string start, end;
            showAllPlaces();
            std::cout << "Enter START: ";
            std::cin >> start;
            std::cout << "Enter END: ";
            std::cin >> end;

            if (places.find(start) != places.end() && places.find(end) != places.end()) {
                double lat1 = places[start].first;
                double lon1 = places[start].second;
                double lat2 = places[end].first;
                double lon2 = places[end].second;

                url = "https://www.google.com/maps/dir/" +
                      std::to_string(lat1) + "," + std::to_string(lon1) + "/" +
                      std::to_string(lat2) + "," + std::to_string(lon2);

                std::cout << "🚀 Opening Route Map (" << start << " to " << end << ")...\n";
                std::string command = "start " + url;
                system(command.c_str());
            } else {
                std::cout << "❌ Invalid locations!\n";
            }
        }
    }

    void viewRouteSequence() {
        std::string start, end;
        showAllPlaces();

        std::cout << "\nEnter START location: ";
        std::cin >> start;
        std::cout << "Enter END location: ";
        std::cin >> end;

        if (!placeExists(start) || !placeExists(end)) {
            std::cout << "❌ Error: Invalid location name!\n";
            return;
        }

        std::vector<std::string> path = findShortestPath(start, end);

        if (path.empty()) {
             std::cout << "❌ No route found between " << start << " and " << end << "!\n";
             return;
        }

        std::cout << "\n" << std::string(50, '-') << "\n";
        std::cout << "🔗 ROUTE SEQUENCE:\n";
        std::cout << std::string(50, '-') << "\n\n";

        for (size_t i = 0; i < path.size(); i++) {
            std::cout << path[i];
            if (i != path.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << "\n\n" << std::string(50, '-') << "\n";
    }

    void calculateFare(const std::vector<std::string>& path, bool studentDiscount = false) {
        if (path.size() < 2) {
            std::cout << "❌ No valid route found!\n";
            return;
        }

        std::vector<SegmentInfo> segments;
        double routeDistance = 0; // Actual travel distance through stops
        int totalTime = 0;

        // ==========================================
        // CHANGE: FARE CALCULATION ON DIRECT DISTANCE
        // ==========================================
        auto startNode = places[path.front()];
        auto endNode = places[path.back()];
        double directDistance = calculateDistance(startNode.first, startNode.second, endNode.first, endNode.second);

        double totalFare = directDistance * BASE_FARE_PER_KM;

        if (studentDiscount) {
            totalFare *= 0.5;
        }
        if (totalFare < 10.0) totalFare = 10.0; // Min fare

        // Loop for generating Sequence Details (Time, Traffic, Path Distance)
        for (size_t i = 0; i < path.size() - 1; i++) {
            SegmentInfo segment;
            segment.from = path[i];
            segment.to = path[i + 1];

            auto A = places[segment.from];
            auto B = places[segment.to];

            segment.distance = calculateDistance(A.first, A.second, B.first, B.second);
            segment.traffic = getTrafficFactor();
            segment.timeFactor = getTimeFactor();
            segment.weatherImpact = weatherSystem.getWeatherImpact(currentWeather);
            segment.trafficColor = getTrafficColor(segment.traffic);

            segment.fare = 0; // Segment wise fare nai, tai 0 set kora holo

            segment.travelTime = static_cast<int>((segment.distance / 20.0) * 60 * segment.traffic);

            segments.push_back(segment);
            routeDistance += segment.distance;
            totalTime += segment.travelTime;
        }

        displayRouteTable(path, segments, routeDistance, totalFare, totalTime, studentDiscount, directDistance);
    }

    void displayRouteTable(const std::vector<std::string>& path,
                          const std::vector<SegmentInfo>& segments,
                          double totalDistance, double totalFare,
                          int totalTime, bool studentDiscount, double directDistance) {

        std::cout << "\n" << std::string(80, '=') << "\n";
        std::cout << "                     🚌 DHAKA BUS ROUTE PLANNER\n";
        std::cout << std::string(80, '=') << "\n\n";

        std::cout << "💰 Base Rate: " << BASE_FARE_PER_KM << " per km (Direct)\n";
        std::cout << "🌤️  Current Weather: " << weatherSystem.getWeatherColor(currentWeather)
                  << " " << currentWeather << "\n";

        std::cout << "📍 Route: ";
        for (size_t i = 0; i < path.size(); i++) {
            std::cout << path[i];
            if (i != path.size() - 1) std::cout << " → ";
        }
        std::cout << "\n\n";

        std::cout << std::string(100, '-') << "\n";
        std::cout << std::left << std::setw(20) << "Segment"
                  << std::setw(12) << "Distance"
                  << std::setw(10) << "Traffic"
                  << std::setw(12) << "Time Factor"
                  << std::setw(10) << "Weather"
                  << std::setw(10) << "Time"
                  << std::setw(15) << "Fare(৳)"
                  << "Status\n";
        std::cout << std::string(100, '-') << "\n";

        for (const auto& segment : segments) {
            std::string segmentName = segment.from + "→" + segment.to;

            std::cout << std::left << std::setw(20) << segmentName
                      << std::fixed << std::setprecision(2)
                      << std::setw(12) << segment.distance
                      << std::setw(10) << segment.traffic
                      << std::setw(12) << segment.timeFactor
                      << std::setw(10) << segment.weatherImpact
                      << std::setw(10) << (std::to_string(segment.travelTime) + "min")
                      << std::setw(15) << "-"  // Segment fare show korbe na
                      << segment.trafficColor << " " << getTrafficStatus(segment.traffic) << "\n";
        }

        std::cout << std::string(100, '=') << "\n";
        std::cout << "📊 JOURNEY SUMMARY:\n";
        std::cout << std::string(50, '-') << "\n";
        std::cout << "Route Distance:  " << std::setw(10) << totalDistance << " km (Actual Path)\n";
        std::cout << "Direct Distance: " << std::setw(10) << directDistance << " km (For Fare)\n";
        std::cout << "Total Fare:      " << std::setw(10) << "৳ " << totalFare;
        if(studentDiscount) std::cout << " (Student Fare Applied)";
        std::cout << "\n";
        std::cout << "Total Time:      " << std::setw(10) << totalTime << " minutes\n";
        std::cout << "Segments:        " << std::setw(10) << segments.size() << "\n";

        std::cout << std::string(50, '-') << "\n";

        std::cout << "\nTraffic Legend: 🟢 Smooth  🟡 Light  🟠 Moderate  🔴 Heavy\n";
    }

    std::string getTrafficStatus(double traffic) {
        if (traffic > 1.5) return "Heavy";
        if (traffic > 1.3) return "Moderate";
        if (traffic > 1.1) return "Light";
        return "Smooth";
    }

    void showAllPlaces() {
        std::cout << "\n📍 AVAILABLE LOCATIONS (" << places.size() << " places):\n";
        std::cout << std::string(35, '-') << "\n";
        int count = 1;
        for (auto& place : places) {
            std::cout << std::setw(2) << count++ << ". " << place.first << "\n";
        }
        std::cout << std::string(35, '-') << "\n";
    }

    bool placeExists(const std::string& name) {
        return places.find(name) != places.end();
    }

    void showWeatherInfo() {
        double impact = weatherSystem.getWeatherImpact(currentWeather);
        std::cout << "\n🌤️  WEATHER INFORMATION\n";
        std::cout << std::string(30, '-') << "\n";
        std::cout << "Condition: " << weatherSystem.getWeatherColor(currentWeather)
                  << " " << currentWeather << "\n";
        std::cout << "Impact: " << impact << "x (Note: No effect on fare)\n";
        std::cout << std::string(30, '-') << "\n";
    }

    void showSystemInfo() {
        std::cout << "\n📊 SYSTEM INFORMATION\n";
        std::cout << std::string(40, '-') << "\n";
        std::cout << "Total Locations: " << places.size() << "\n";
        std::cout << "Connected Routes: " << graph.size() << "\n";
        std::cout << "Current Weather: " << currentWeather << "\n";
        std::cout << "Base Fare Rate: ৳" << BASE_FARE_PER_KM << " per km\n";
        std::cout << "Student Discount: 50% OFF\n";
        std::cout << "Minimum Fare: ৳10.00\n";
        std::cout << std::string(40, '-') << "\n";
    }
};

void displayMainMenu() {
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "           🚌 DHAKA BUS ROUTE PLANNER\n";
    std::cout << "        Base Fare: ৳2.45 per km\n";
    std::cout << std::string(50, '=') << "\n";

    std::cout << "📋 MAIN MENU:\n";
    std::cout << "1. 🗺️  Find Route & Calculate Fare\n";
    std::cout << "2. 📍 Show All Locations\n";
    std::cout << "3. ➕ Add New Place\n";
    std::cout << "4. 🌤️  Update Weather\n";
    std::cout << "5. ℹ️  Show Weather Info\n";
    std::cout << "6. 📊 System Information\n";
    std::cout << "7. 🌏 Open Online Map (Google Maps)\n";
    std::cout << "8. 🔗 View Route Sequence (Text)\n";
    std::cout << "9. ❌ Exit\n";
    std::cout << "Choose option (1-9): ";
}

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif

    std::cout << "Starting Dhaka Bus Route Planner...\n";
    DhakaBusSystem busSystem;

    int choice;
    do {
        displayMainMenu();
        std::cin >> choice;

        switch(choice) {
            case 1: {
                std::string start, end;
                char student;

                busSystem.showAllPlaces();

                std::cout << "\nEnter START location: ";
                std::cin >> start;

                std::cout << "Enter END location: ";
                std::cin >> end;

                std::cout << "Student discount? (y/n): ";
                std::cin >> student;

                if (!busSystem.placeExists(start) || !busSystem.placeExists(end)) {
                    std::cout << "❌ Error: Invalid location name!\n";
                    break;
                }

                std::vector<std::string> path = busSystem.findShortestPath(start, end);
                if (!path.empty()) {
                    busSystem.calculateFare(path, (student == 'y' || student == 'Y'));
                } else {
                    std::cout << "❌ No route found between " << start << " and " << end << "!\n";
                }
                break;
            }
            case 2:
                busSystem.showAllPlaces();
                break;
            case 3:
                busSystem.addNewPlace();
                break;
            case 4:
                busSystem.updateWeather();
                break;
            case 5:
                busSystem.showWeatherInfo();
                break;
            case 6:
                busSystem.showSystemInfo();
                break;
            case 7:
                busSystem.openOnlineMap();
                break;
            case 8:
                busSystem.viewRouteSequence();
                break;
            case 9:
                std::cout << "\n🙏 Thank you for using Dhaka Bus Route Planner!\n";
                std::cout << "🚌 Safe travels! 🌟\n";
                break;
            default:
                std::cout << "❌ Invalid choice! Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}
