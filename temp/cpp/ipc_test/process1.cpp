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

    Process *proc1 = new Process("process1");

    qID = proc1->createMsgQueue();
    cout << "Queue ID:" << qID << endl;

    signal(SIGINT, &int_handler);
    for(;;) {
        cout << "Waiting to receive message [Ctrl-C to exit]: ";
        proc1->getMsg();
    }
}
