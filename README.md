elos
====

elos synthetic workload generator
Steps for generating synthetic trace.

1. Transform binary trace data to text format.
  This step checks that the time stamps are in the right order, there is no appraent overflows and that trace files are not corrupted.

  >parse_sg/gen_txt.sh "binary trace directory" "txt trace directory"

2. Run csim.
  Set up cache_sim.cfg file for the test run.
  You need to set ROA and RLA coverage you want to test.
  Multithreading only helps if you have enought memory to support it.
  Output directroy of where you want to have the results stored.
  duration specifies how many minutes of trace you will want to run.
  trace are the input trace to be tested.

  >extract/csim "cfg file"

3. Gen Synth.
  This script only works for 4 traces that are curretly being used.
  TODO: generalize the script.

  >cache_reuslt/synth_gen.R

4. Verification.
  Rerun csim on generated synthetic trace for verification.

5. Plot.

  >cache_result/plot_cache_hit.R
