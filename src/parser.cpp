#include "parser.h"



LoaderMode parseCmdLine(int argc, char *argv[],Loader lFile,CmdLineOpts opts)
{
    string mode = argv[1];
    if(mode == "train"){

    }else if(mode == "predict"){

    }else if(mode == "video"){

    }
}

void tokenize(const string & str,vector<string> & tokens,const string & delimiters)
{
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
}
