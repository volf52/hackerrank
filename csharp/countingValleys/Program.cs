using System;

namespace countingValleys
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = "DDUUDDUDUUUD";
            var len = 12;
            var res = countingValleys(len, s);
            Console.WriteLine($"No of valleys: {res} {Environment.NewLine}");
        }

        static int countingValleys(int n, string s)
        {
            var i = 0;
            var valleys = 0;
            var insideValley = false;
            var level = 0;
            while (i < (n - 1))
            {

                if (s[i] == 'U')
                    level++;
                else level--;

                if ((!insideValley) && (level < 0))
                {
                    valleys++;
                    insideValley = true;
                }
                else if ((insideValley) && (level >= 0))
                {
                    insideValley = false;
                }

                i++;
            }

            return valleys;
        }
    }
}
