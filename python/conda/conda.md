### Conda commands

##### get info cache paths

~~~
conda info > conda_info.txt
~~~

##### packages cache path

~~~
C:\Users\stm32\Miniconda3\pkgs\
~~~

##### install on spesific envs

~~~
conda install --name <env> <package>
~~~

##### clean conda cache

~~~
conda clean -a
~~~

##### required packages

~~~
numpy pandas matplotlib seaborn tensorflow keras jupyter
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

###### path adjusment

~~~
RUN_ADJUST.bat
~~~

~~~
RUN_CMD.bat
python -m ipykernel install --user
~~~

###### run notebook

~~~
RUN_JUPYTER.bat
~~~