[build-menu]
FT_01_LB=_Build
FT_01_CM=g++ -lpthread -Wall -g -o "%e" "%f"
FT_01_WD=
FT_02_LB=_Lint
FT_02_CM=cppcheck --language=c++ --enable=warning,style --template=gcc "%f"
FT_02_WD=
EX_00_LB=_Execute
EX_00_CM="./%e"
EX_00_WD=
FT_00_LB=_Compile
FT_00_CM=g++ -Wall -c -g "%f"
FT_00_WD=
