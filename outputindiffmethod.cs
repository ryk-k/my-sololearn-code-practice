using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SoloLearn
{
	class Program
	{
		public static void Main(string[] args)
		{
			string cityName = "Toronto";
			Console.WriteLine(cityName);	
			cityName = ChangeCity(cityName);
			Console.WriteLine(cityName);	
		}
		
		static string ChangeCity (string newCityName){ 
			newCityName = "Vancouver";	
			return newCityName;
		}
	}
}



			    
	


