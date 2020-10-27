clang++ -std=c++17 -O3 -o ShellSaying Main.cpp

echo -e "/bin/sh -c \"${PWD}/ShellSaying\"\n" >> ~/.zshrc
echo -e "/bin/sh -c \"${PWD}/ShellSaying\"\n" >> ~/.bashrc

echo -e "ShellSaying Install OK!\n"
echo -e "Input your saying to ~/.Shell_Saying\n"
echo -e "The ShellSaying will random output them when you login shell\n"
echo -e "random output is in units of rows\n"