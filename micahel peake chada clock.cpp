#include <iostream>
#include <iomanip>

class Clock {
private:
    int hour;
    int minute;
    int second;

public:
    Clock(int h, int m, int s) : hour(h), minute(m), second(s) {}

    void display12Hour() {
        int display_hour = hour % 12;
        std::cout << std::setw(2) << std::setfill('0') << display_hour << ":"
                  << std::setw(2) << std::setfill('0') << minute << ":"
                  << std::setw(2) << std::setfill('0') << second;
        if (hour >= 12)
            std::cout << " PM";
        else
            std::cout << " AM";
        std::cout << std::endl;
    }

    void display24Hour() {
        std::cout << std::setw(2) << std::setfill('0') << hour << ":"
                  << std::setw(2) << std::setfill('0') << minute << ":"
                  << std::setw(2) << std::setfill('0') << second << std::endl;
    }

    void addHour() {
        hour = (hour + 1) % 24;
    }

    void addMinute() {
        minute = (minute + 1) % 60;
    }

    void addSecond() {
        second = (second + 1) % 60;
    }

    // Getter functions if needed
};

int main() {
    int initial_hour, initial_minute, initial_second;
    
    // Get initial time from the user
    std::cout << "Enter initial hour: ";
    std::cin >> initial_hour;
    std::cout << "Enter initial minute: ";
    std::cin >> initial_minute;
    std::cout << "Enter initial second: ";
    std::cin >> initial_second;

    Clock clock(initial_hour, initial_minute, initial_second);

    char choice;
    do {
        // Display menu
        std::cout << "MENU:" << std::endl;
        std::cout << "1. Add Hour" << std::endl;
        std::cout << "2. Add Minute" << std::endl;
        std::cout << "3. Add Second" << std::endl;
        std::cout << "4. Display Time (12-hour format)" << std::endl;
        std::cout << "5. Display Time (24-hour format)" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                clock.addHour();
                break;
            case '2':
                clock.addMinute();
                break;
            case '3':
                clock.addSecond();
                break;
            case '4':
                std::cout << "12-Hour Clock: ";
                clock.display12Hour();
                break;
            case '5':
                std::cout << "24-Hour Clock: ";
                clock.display24Hour();
                break;
            case '6':
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != '6');

    return 0;
}
