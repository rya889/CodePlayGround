using System;
using System.IO;
using System.Collections.Generic;

namespace DotNet
{
    public class LeftRotation
    {
        int d;
        int[] arr;
        public LeftRotation(int d_in, int[] arr_in)
        {
            d = d_in;
            arr = arr_in;
        }
        public int[] solve()
        {
            int[] solution = new int[arr.Length];
            int x = 0;
            for (int i = d; i< arr.Length; i++)
            {
                solution[x] = arr[i];
                x++;
            }
            for (int i = 0; i< d; i++)
            {
                solution[x] = arr[i];
                x++;
            }
            return solution;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            int n, d = 0;
            int[] arr;
            using (StreamReader sr = new StreamReader("../input.txt"))
            {
                String line;
                line = sr.ReadLine();
                string[] str_split = line.Split(" ");
                Int32.TryParse(str_split[0], out n);
                Int32.TryParse(str_split[1], out d);
                line = sr.ReadLine();
                str_split = line.Split(" ");
                arr = Array.ConvertAll(str_split, int.Parse);
            }
            int[] sol = (new LeftRotation(d,arr)).solve();
            Console.WriteLine(string.Join(",",sol));
        }
    }
}
