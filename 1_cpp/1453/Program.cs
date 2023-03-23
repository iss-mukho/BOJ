using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1453
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input;
            int[] customer = new int[101];

            int N = int.Parse(Console.ReadLine());
            int cnt = 0;
            string n = Console.ReadLine();
            input = n.Split(' ');

            for(int j = 0; j < input.Length; j++)
            {
                if (customer[Convert.ToInt32(input[j])] == 0)
                {
                    customer[Convert.ToInt32(input[j])] = 1;
                }
                else
                {
                    cnt++;
                }
            }
            Console.WriteLine(cnt);
        }
    }
}
