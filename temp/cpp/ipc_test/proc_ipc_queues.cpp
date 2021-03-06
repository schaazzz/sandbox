#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include "proc_base.hpp"
#include "proc_ipc_queues.hpp"

ProcIPCQueues::ProcIPCQueues(std::string process_name) : ProcBase(process_name) {}

int ProcIPCQueues::CreateMsgQueue(void) {
    if((key_val_ = ftok(get_current_dir_name(), '0')) == -1) {
        return (-1);
    }

    if((q_id_ = msgget(key_val_, IPC_CREAT | 0660)) == -1) {
        return (-1);
    }

    return (q_id_);
}

void ProcIPCQueues::SendMsg(std::string msg) {
    int length = sizeof(send_buff_) - sizeof(long);

    std::memcpy(send_buff_. mtext, msg.data(), sizeof(msg.data()));
    send_buff_.mtype = 9;

    if(msgsnd(q_id_, &send_buff_, length, 0)  == -1) {
        std::cout << "Error while sending message" << std::endl;
    }
}

std::string ProcIPCQueues::GetMsg() {
    int length = sizeof(rcv_buff_) - sizeof(long);
    std::string msg = "";
    if(msgrcv(q_id_, &rcv_buff_, length, 9, 0)  == -1) {
        std::cout << "Error while receiving message" << std::endl;
        msg = " RECEIVE ERROR!";
    } else {
        msg = rcv_buff_.mtext;
    }

    return msg;
}
