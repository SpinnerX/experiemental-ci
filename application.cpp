#include <print>
#include <string>

#include <functional>
#include <map>
#include <list>
#include <unordered_set>

class event_dispatcher {
public:
    event_dispatcher(std::string p_name) {
    }


    void add_event(std::function<void()> p_event_callback) {
        p_event_callback();
    }
};

int main(){
    event_dispatcher dispatcher("Test");

    dispatcher.add_event([](){
        std::println("Add Event!!");
    });
    return 0;
}
