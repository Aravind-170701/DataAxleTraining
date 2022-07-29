using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Data.Entity;
using System.Linq;
using System.Web;

namespace demo.Models
{
    public class DataContext :DbContext
    {
        public DbSet<User> Users { get; set; }
    }
}
