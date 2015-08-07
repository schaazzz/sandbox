class BaseProc {
private:
    int             q_id_;
    int             key_val_;
    std::string     process_name_;

    struct {
        long mtype;
        char mtext[128];
    } send_buff_, rcv_buff_;

public:
    BaseProc(std::string processName);
    int CreateMsgQueue(void);
    void SendMsg(std::string msg);
    std::string GetMsg(void);

    static void IntHandler(int sigNum);
};
