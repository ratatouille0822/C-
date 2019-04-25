#include "pch.h"
#include <iostream>

using namespace std;

class AbstractCPU
{
public:
	virtual void CpuCalc() = 0;
	virtual ~AbstractCPU()
	{
		cout << "Abstruct CPU destructed" << endl;
	}
};


class AbstractGPU
{
public:
	virtual void GpuCalc() = 0;
	virtual ~AbstractGPU()
	{
		cout << "Abstruct GPU destructed" << endl;
	}
};


class AbstractMEM
{
public:
	virtual void MEMRun() = 0;
	virtual ~AbstractMEM()
	{
		cout << "Abstruct MEM destructed" << endl;
	}
};

class IntelCPU : public AbstractCPU
{
public:
	virtual void CpuCalc()
	{
		cout << "Intel CPU Calculating !" << endl;
	}
	~IntelCPU()
	{
		cout << "intel CPU runs no more" << endl;
	}
};

class NvidiaGPU : public AbstractGPU
{
public:
	virtual void GpuCalc()
	{
		cout << "NVidia GPU Calculating !" << endl;
	}
	~NvidiaGPU()
	{
		cout << "NV gpu runs no more" << endl;
	}

};

class UniMEM : public AbstractMEM
{
public:
	virtual void MEMRun()
	{
		cout << "Uni MEM Runs !" << endl;
	}
	~UniMEM()
	{
		cout << "uni mem runs no more" << endl;
	}
	

};

class Computer
{
public:
	Computer(AbstractCPU* cpu, AbstractGPU* gpu, AbstractMEM* mem)
	{
		this->cpu = cpu;
		this->gpu = gpu;	
		this->mem = mem;
	}

	AbstractCPU* cpu;
	AbstractGPU* gpu;
	AbstractMEM* mem;

	void ComputerRuns()
	{
		cpu->CpuCalc();
		gpu->GpuCalc();
		mem->MEMRun();
	}
	~Computer()
	{
		delete cpu;
		delete gpu;
		delete mem;
	}

};

void test01()
{
	IntelCPU* intel_cpu = new IntelCPU;
	NvidiaGPU* nvidia_gpu = new NvidiaGPU;
	UniMEM* uni_mem = new UniMEM;

	Computer* computer = new Computer(intel_cpu, nvidia_gpu, uni_mem);
	computer->ComputerRuns();

	Computer* computer1;
	decltype(computer) computer2;

	delete computer;
}
int main()
{
	test01();
    std::cout << "Hello World!\n"; 
}

















