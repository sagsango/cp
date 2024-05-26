$  g++ -o solution a.cpp \
   this will create compiled file named solution \
$  python interactive_runner.py python3 testing_tool.py 0 -- ./solution   \
   to run 0 th test \
$  python interactive_runner.py python3 testing_tool.py 1 -- ./solution   \
   to run 1 st test \
$  python interactive_runner.py python3 testing_tool.py 2 -- ./solution   \
   to run 2 nd test 
   
#NOTE \
      a) interactive_runner.py will be same for all solution testing as helper \
      b) Only testing_tool.py will changed as diff problem \
      c) We have to add 0, 1 or 2 to run that test \
      d) Above solution is correct 0 and 1 test case but will give wrong ans for test 2 see the message.
