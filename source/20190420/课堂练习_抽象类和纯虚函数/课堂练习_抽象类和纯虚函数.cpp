#include "pch.h"
#include <iostream>

using namespace std;

class AbstractCPU
{
public:
	virtual void CpuCalc() = 0;
};


class AbstractGPU
{
public:
	virtual void GpuCalc() = 0;
};


class AbstractMEM
{
public:
	virtual void MEMRun() = 0;
};

class IntelCPU : public AbstractCPU
{
	virtual void CpuCalc()
	{
		cout << "Intel CPU Calculating !" << endl;
	}
};

class NvidiaGPU : public AbstractGPU
{
	virtual void GpuCalc()
	{
		cout << "NVidia GPU Calculating !" << endl;
	}

};

class UniMEM : public AbstractMEM
{
	virtual void MEMRun()
	{
		cout << "Uni MEM Runs !" << endl;
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

};

void test01()
{
	IntelCPU* intel_cpu = new IntelCPU;
	NvidiaGPU* nvidia_gpu = new NvidiaGPU;
	UniMEM* uni_mem = new UniMEM;

	Computer* computer = new Computer(intel_cpu, nvidia_gpu, uni_mem);
	computer->ComputerRuns();
}
int main()
{
	test01();
    std::cout << "Hello World!\n"; 
}

















