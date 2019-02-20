
#ifndef SERIALIZABLE_HPP_
#define SERIALIZABLE_HPP_

class Serializable {
    public:  
        virtual std::string getSerializedData(void) = 0;
        virtual void setSerializedData(std::string serializedData) = 0;
        virtual ~Serializable() {}
};

#endif
