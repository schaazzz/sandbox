#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include "process.hpp"

Process::Process(std::string processName) {
    this->processName = processName;
    std::cout << processName + " created!" << std::endl;
}

void Process::intHandler(int sigNum) {
    std::cout << "\nExiting, thank you for playing...\n";
    exit(1);
}

int Process::createMsgQueue(void) {
    if((keyVal = ftok(get_current_dir_name(), '0')) == -1) {
        return (-1);
    }

    if((qID = msgget(keyVal, IPC_CREAT | 0660)) == -1) {
        return (-1);
    }

    return (qID);
}

void Process::sendMsg(std::string msg) {
    int length = sizeof(sendBuff) - sizeof(long);

    std::memcpy(sendBuff.mtext, msg.data(), sizeof(msg.data()));
    sendBuff.mtype = 9;

    if(msgsnd(qID, &sendBuff, length, 0)  == -1) {
        std::cout << "Error while sending message" << std::endl;
    }
}

std::string Process::getMsg() {
    int length = sizeof(rcvBuff) - sizeof(long);
    std::string msg = "";
    if(msgrcv(qID, &rcvBuff, length, 9, 0)  == -1) {
        std::cout << "Error while receiving message" << std::endl;
        msg = " RECEIVE ERROR!";
    } else {
        msg = rcvBuff.mtext;
    }

    return msg;
}
