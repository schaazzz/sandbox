class ProcBase {
private:
    /* Private class members */

protected:
    /* Protected class members */
    std::string     process_name_;

public:
    /* Public class members */
    ProcBase(std::string process_name);
    virtual void SendMsg(std::string msg) = 0;
    virtual std::string GetMsg(void) = 0;

    static void IntHandler(int sigNum);
};
