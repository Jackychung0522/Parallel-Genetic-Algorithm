#include "include/linked_list.h"
#include <include/machine_base.h>

MachineBase::MachineBase(unsigned int machine_no):machine_no(machine_no)
{
	this->init();
}

__device__ __host__ void MachineBase::init()
{
	size_of_jobs = 0;
	root = tail = NULL;
}

__device__ __host__ void MachineBase::addJob(JobBase * job)
{
	if (size_of_jobs == 0) {
		tail = root = job;	
	} else {
		tail->setNext(job); // add into the list
		job->setPrev(tail); // connect to prev
		tail = job;	// move the tail
	}
	++size_of_jobs;
}

__device__ __host__ unsigned int MachineBase::getSizeOfJobs()
{
	return size_of_jobs;
}

__device__ __host__ void MachineBase::sortJob()
{
	root = (JobBase *)linkedListMergeSort(root);
}

