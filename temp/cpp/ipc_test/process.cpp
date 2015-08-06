#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <cstring>
#include "process.hpp"

Process::Process(std::string processName) {
    this->processName = processName;
    std::cout << processName + " created!" << std::endl;
}

int Process::createMsgQueue(void) {
    std::cout << get_current_dir_name() << std::endl;

    if((keyVal = ftok(get_current_dir_name(), '0')) == -1) {
        //std::cout << "keyVal: " << keyVal << std::endl;
        return (-1);
    }

    if((qID = msgget(keyVal, IPC_CREAT | 0660)) == -1) {
        //std::cout << "qID: " << qID << std::endl;
        return (-1);
    }

    return (qID);
}

void Process::sendMsg(std::string msg) {
    int length = sizeof(sendBuff) - sizeof(long);

    std::cout << msg << std::endl;
    std::memcpy(sendBuff.mtext, msg.data(), sizeof(msg.data()));
    sendBuff.mtype = 9;

    if(msgsnd(qID, &sendBuff, length, 0)  == -1) {
        std::cout << "Error while sending message" << std::endl;
    }
}

void Process::getMsg() {
    int length = sizeof(rcvBuff) - sizeof(long);

    if(msgrcv(qID, &rcvBuff, length, 9, 0)  == -1) {
        std::cout << "Error while receiving message" << std::endl;
    } else {
        std::cout << rcvBuff.mtext << std::endl;
    }
}
