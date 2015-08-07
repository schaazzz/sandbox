#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include "proc_base.hpp"

ProcBase::ProcBase(std::string process_name) {
    process_name_ = process_name;
    std::cout << process_name_ + " created!" << std::endl;
}

void ProcBase::IntHandler(int sig_num) {
    std::cout << "\nExiting, thank you for playing...\n";
    exit(1);
}

void ProcBase::SendMsg(std::string msg) {
}

std::string ProcBase::GetMsg() {
    return "";
}
