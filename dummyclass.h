#ifndef DUMMYCLASS_H
#define DUMMYCLASS_H

class DummyClass {
public:
    DummyClass()
    {}
    DummyClass(const DummyClass & obj)
    {}
    void sampleMemberFunction(int x)
    {
        std::cout<<"Inside sampleMemberFunction "<<x<<std::endl;
    }
};

#endif // DUMMYCLASS_H
