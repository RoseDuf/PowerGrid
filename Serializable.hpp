
class Serializable {
    public:  
        virtual std::string getSerializedData(void) = 0;
        virtual void setSerializedData(std::string serializedData) = 0;
};
