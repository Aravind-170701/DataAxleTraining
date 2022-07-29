using demo.Models;
using Microsoft.AspNetCore.Mvc;

namespace demo.Controllers
{
    public class UserController : Controller
    {
        private DataContext db = new DataContext();
        public IActionResult Index()
        {
            return View(db.Users.ToList());
        }

        public ActionResult Register()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Register(User usr)
        {
            if (ModelState.IsValid)
            {
                db.Users.Add(usr);
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            else
            {
                ModelState.AddModelError("", "Some Error Occured");
            }
            return View(usr);

        }

        public ActionResult Login()
        {
            return View();
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Login(User users)
        {
            if (ModelState.IsValid)
            {
               using(DataContext db = new DataContext())
                {
                    var obj = db.Users.Where(u => u.Username.Equals(users.Username) && u.Password.Equals(users.Password)).FirstOrDefault();
                    if(obj != null)
                    {
                        return RedirectToAction("LoggedIn");

                    }
                }
            }
            
            return View(users);
        }

        public ActionResult LoggedIn()
        {
                return RedirectToAction("Index");
        }
    }
}
