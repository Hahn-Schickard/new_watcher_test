#include "watcher.hpp"

#include <csignal>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex std_mx;
unique_ptr<wtr::watch> watcher;

void print(const string &msg);
void printEvent(const wtr::event *event, uint level = 0);

void onEvent(const wtr::event &ev) {
  // auto event = make_unique<wtr::event>(ev);
  printEvent(&ev);
  print(string(80, '='));
}

static void stopHandler(int) {
  print("");
  print("Received stop signal!");
  if (watcher) {
    print("Stopping filesystem event watcher");
    print(string(80, '~'));
    watcher->close();
  } else {
    print("Filesystem event watcher is not running");
  }
  exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
  auto observed = filesystem::current_path();

  if (argc > 1) {
    auto path_string = string(argv[1]);
    auto user_path = filesystem::path(path_string);
    if (filesystem::exists(user_path)) {
      if (user_path.is_relative()) {
        user_path = filesystem::canonical(observed / user_path);
      }
      observed = user_path;
    } else {
      print("Given path " + user_path.string() + " does not exist");
    }
  }

  print("Observing " + observed.string());
  print(string(80, '~'));
  watcher = make_unique<wtr::watch>(observed, &onEvent);

  signal(SIGINT, stopHandler);

  while (true) {
    this_thread::sleep_for(500ms);
  }

  return 0;
}

void print(const string &msg) {
  lock_guard print_lock(std_mx);
  cout << msg << endl;
}

void printEvent(const wtr::event *event, uint level) {
  auto offset = string(level, ' ');
  if (event) {
    stringstream ss;
    ss << offset << "Event Type: " << wtr::to<string>(event->effect_type)
       << endl
       << offset << "Path Type: " << wtr::to<string>(event->path_type) << endl
       << offset << "Path Name: " << event->path_name.string() << endl
       << offset << "Effect Time: " << to_string(event->effect_time) << endl
       << offset << "Associated event: ";
    print(ss.str());
    // this would be a lot neater if event->associated was shared_ptr
    printEvent(event->associated.get(), level + 1);
  } else {
    print(offset + "None");
  }
}