using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace _5
{
    class Program
    {
        
        public static string CalculateMD5Hash(string input)
        {
            // step 1, calculate MD5 hash from input
            MD5 md5 = System.Security.Cryptography.MD5.Create();
            byte[] inputBytes = System.Text.Encoding.ASCII.GetBytes(input);
            byte[] hash = md5.ComputeHash(inputBytes);
            // step 2, convert byte array to hex string
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < hash.Length; i++)
            {

                sb.Append(hash[i].ToString("X2"));
            }
            return sb.ToString();
        }

        static void Main(string[] args)
        {
            int i = 0;
            int a = 0;
            string output1 = "";
            string output2 = "        ";
            for (int y = 0; output2.Contains(" "); y++)
            {
                while (! CalculateMD5Hash("abbhdwsy" + i).StartsWith("00000")) i++;
                string s = CalculateMD5Hash("abbhdwsy" + i);
                if (y < 8)  output1 += s[5];    
                
                StringBuilder strB = new StringBuilder(output2);
                int pos = s[5] - '0';
                if (pos<= 7 && pos>= 0)
                {
                    if (strB[pos] == ' ' ) strB[pos] = s[6]; 
                output2 = strB.ToString();
                    a++;
                }
                i++;
            }          
            Console.WriteLine(output1);
            Console.WriteLine(output2);
            Console.ReadLine();
        }
    }
}

