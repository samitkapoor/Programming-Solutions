class Solution
{
public:
    string generator(string x)
    {

        string temp = "";

        for (int i = 0; i < (int)x.length(); i++)
        {
            char c = x[i];
            int j = i;
            int counter = 0;

            while (c == x[j])
            {
                counter++;
                j++;
            }

            temp += to_string(counter);
            temp += x[i];

            i = j - 1;
        }

        return temp;
    }

    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string x = "1";

        string result = "";

        for (int i = 0; i < n - 1; i++)
        {
            result = generator(x);
            x = result;
        }

        return result;
    }
};