# below code can split string using custom delimeter

```
#include <vector>
#include <string>
#include <sstream>

int main()
{
    string str("Split me by custom character.");
    string buf;                 
    stringstream ss(str); 

    vector<std::string> tokens;
    <!-- buf gets space splitted str words -->
    <!-- if we use while(getline(ss,buf,',')) then it splits for each comma!! -->
    while (ss >> buf)
        tokens.push_back(buf);

    return 0;
}
```