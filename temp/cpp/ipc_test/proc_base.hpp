class ProcBase {
private:
    std::string     process_name_;
    
public:
    ProcBase(std::string process_name);
    virtual void SendMsg(std::string msg);
    virtual std::string GetMsg(void);

    static void IntHandler(int sigNum);
};
