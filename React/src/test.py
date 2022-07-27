from selenium import webdriver
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.by import By
import pdb
import time


driver = webdriver.Chrome(executable_path=ChromeDriverManager().install())
driver.maximize_window()
driver.get("http://localhost:3000/")

# driver.find_element(By.ID,'title').send_keys('Aravind')

# driver.find_element(By.ID,'description').send_keys('Test Description')
# driver.find_element(By.ID,'author').send_keys('Koi toh hai')
# driver.find_element(By.ID,'reading_time').send_keys(6)


# driver.find_element(By.XPATH,"//button[@id='submit_button']").click()


time.sleep(5)
a = driver.find_elements(By.XPATH,"//p[@id='paragraph_id']")
print("Output:",a)

pdb.set_trace()
driver.close()