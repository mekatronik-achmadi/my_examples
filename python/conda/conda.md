### Conda commands

##### conda basic commands

~~~
conda search <package>
conda install <package>
conda list | grep <package>
conda update <package>
conda remove <package>
~~~

##### clean conda cache

~~~
conda clean -a
~~~

##### recommended packages

~~~
numpy pandas matplotlib seaborn tensorflow keras scikit-learn jupyter
~~~

##### get info cache paths

~~~
conda info > conda_info.txt
~~~

##### portable packaging

~~~
C:\ProgramData\Miniconda3\
~~~

~~~
cp -vf portable/*.bat Miniconda3/
cp -vf portable/*.py Miniconda3/
~~~

~~~
zip -r -0 Miniconda3_Portable.zip Miniconda3/
~~~

###### portable install

~~~
RUN_ADJUST.bat
~~~

~~~
RUN_CMD.bat
python -m ipykernel install --user
~~~

###### run console

~~~
RUN_CMD.bat
python
~~~

###### run notebook

~~~
RUN_JUPYTER.bat
~~~

~~~
http://localhost:8888/?token=************************************************
~~~

##### packages cache path

~~~
C:\Users\stm32\Miniconda3\pkgs\
~~~

##### install on spesific envs

~~~
conda install --name <env> <package>
~~~

##### example EnVars

~~~
C:\Users\stm32\Miniconda3;C:\Users\stm32\Miniconda3\Library\mingw-w64\bin;C:\Users\stm32\Miniconda3\Library\usr\bin;C:\Users\stm32\Miniconda3\Library\bin;C:\Users\stm32\Miniconda3\Scripts
~~~

###### path file to check

~~~
Miniconda3\qt.conf
Miniconda3\etc\profile.d\conda.sh
Miniconda3\etc\profile.d\conda.csh
Miniconda3\etc\fish\conf.d\conda.fish
~~~