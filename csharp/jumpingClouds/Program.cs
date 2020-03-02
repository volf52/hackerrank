using System;

namespace jumpingClouds
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[] { 0, 0, 0, 1, 0, 0 };
            var res = getJumps(arr);
            Console.WriteLine($"The results is {res}\n");
        }

        static int getJumps(int[] c)
        {
            var n = c.Length;
            int[] mem = new int[n];
            var i = 0;
            for (i = 0; i < n; i++)
            {
                mem[i] = -1;
            }
            mem[0] = 0;
            if (c[1] == 1)
                mem[1] = n;
            else mem[1] = 1;

            i = 2;
            while (i < n)
            {
                if (c[i] == 1) mem[i] = n;
                else mem[i] = Math.Min(mem[i - 1], mem[i - 2]) + 1;
                i++;
            }
            return mem[n - 1];
        }
    }
}
