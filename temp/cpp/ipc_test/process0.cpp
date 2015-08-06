#include <iostream>
#include <string>
#include <signal.h>
#include <cstdlib>
#include "process.hpp"

using namespace std;

void int_handler(int sig_num) {
    cout << "\nExiting, thank you for playing...\n";
    exit(1);
}

int main(void) {
    int qID = -1;
    string msg;

    Process *proc0 = new Process("process0");

    qID = proc0->createMsgQueue();
    cout << "Queue ID:" << qID << endl;

    signal(SIGINT, &int_handler);
    for(;;) {
        cout << "Enter text to send [Ctrl-C to exit]: ";
        cin >> msg;
        proc0->sendMsg(msg);
    }
}
