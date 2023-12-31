#pragma once

class EventDispatcher {
private:
  struct Listener {
    const char *eventName;
    std::function<void(void *)> callback;
    bool isOnce;
  };
  std::vector<Listener> listeners;

public:
  template <typename EventType> void on(std::function<void(EventType *)> fn) {
    this->listeners.push_back(
        Listener{EventType::Name, [=](void *e) { fn((EventType *)e); }, false});
  }

  template <typename EventType> void once(std::function<void(EventType *)> fn) {
    this->listeners.push_back(
        Listener{EventType::Name, [=](void *e) { fn((EventType *)e); }, true});
  }

  template <typename EventType> void dispatch(EventType event) {
    for (auto it = this->listeners.begin(); it != this->listeners.end(); ++it) {
      if (strcmp(it->eventName, EventType::Name) == 0) {
        it->callback(&event);

        if (it->isOnce) {
          this->listeners.erase(it--);
        }
      }
    }
  }
};