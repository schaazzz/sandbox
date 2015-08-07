class ProcIPCQueues : public ProcBase {
private:
    int             q_id_;
    int             key_val_;

    struct {
        long mtype;
        char mtext[128];
    } send_buff_, rcv_buff_;

public:
    ProcIPCQueues(std::string process_name_);
    int CreateMsgQueue(void);
    void SendMsg(std::string msg);
    std::string GetMsg(void);
};
