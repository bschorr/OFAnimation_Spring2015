##Submitting homework

1. Follow [these intructions](https://help.github.com/articles/set-up-git/) to install git in your machine. You can follow them up to the end of the "setting up git" section.

2. Create a [GitHub](https://www.github.com) account if you don't have one already.

3. With your GitHub account set up, create a repo for this class that you'll use to submit your homework.  Name it as follows, ```[FirstnameLastname]_OFanimation2015``` (ex: 'BernardoSchorr_OFanimation2015' ). Optional but very useful: check the "Initialize this repository with a README" option when creating the repo.

4. Clone your repo inside the "Apps" folder of the OF structure.

5. Add a [```.gitignore```](https://gist.github.com/ofZach/3707086) file to your repo. This will tell git to avoid certain files, such as compiled object code (.app / .exes) and system files. This helps to keep your repos light. Zach Lieberman wrote a very useful .gitignore file for OF. Get it [here](https://gist.github.com/ofZach/3707086).

6. Save  your apps in the FIRST level of your repo folder. Do not make subfolders. Organize your repo by naming the files following the scheme ```[WEEK_NUMBER]_[HOMEWORK_NUMBER]_[NAME]```. For Example:

```
	openFrameworks/
		addons/
		apps/
			[your_NID]_sims2014/
				w01_h01_blabla/
				w01_h02_blabla/
				w02_h01_blabla/ 
				w03_h01_blabla/ 
				…/
				…/
		libs/
		examples/
		sims2014/
		sims2014_students/
 ```