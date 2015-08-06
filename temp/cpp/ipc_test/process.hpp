#define __IPC_USE_MSG_QUEUES    (1)

class Process {
private:
    int             qID;
    int             keyVal;
    std::string     processName;

    struct {
        long mtype;
        char mtext[128];
    } sendBuff, rcvBuff;

public:
    Process(std::string processName);
    int createMsgQueue(void);
    void sendMsg(std::string msg);
    void getMsg(void);
};
