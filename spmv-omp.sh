#!/bin/bash
#SBATCH --partition=short   ### Partition
#SBATCH --job-name=HelloOMP ### Job Name
#SBATCH --time=00:10:00     ### WallTime
#SBATCH --nodes=1           ### Number of Nodes
#SBATCH --ntasks-per-node=1 ### Number of tasks (MPI processes)
#SBATCH --cpus-per-task=28  ### Number of threads per task (OMP threads)
#SBATCH --account=hpctensor
#SBATCH --mail-user=idshpang@ajou.ac.kr
#SBATCH --mail-type=ALL
 
export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK
 
./hb_load arc130/arc130.mtx
