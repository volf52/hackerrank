using System;
using System.Collections.Generic;

namespace sock_merchant
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 9;
            int[] ar = {10, 20, 20, 10, 10, 30, 50, 10, 20};
            int res = sockMerchant(n, ar);
            Console.WriteLine(res);
        }


        static int sockMerchant(int n, int[] ar)
        {
            int count = 0;
            var table = new Dictionary<int, int>();
            foreach (var el in ar)
            {
                if (table.ContainsKey(el))
                {
                    table[el] = table[el] + 1;
                }
                else
                {
                    table.Add(el, 1);
                }
            }

            foreach (var key in table.Keys)
            {
                count += table[key] / 2;
            }
            
            
            return count;
        }
    }
}