#include <opencv2/opencv.hpp>
//#include <boost/lexical_cast.hpp>
#include <exception>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <cmath>
#include <ctime>
#include <iterator>
#include <string>


using namespace std;
template <typename T>
class assign_const
        {
        private: T const_value;
        public : assign_const(T n) : const_value(n){}
                 void operator()(T& x){ x = const_value; }
        };
template <typename T>
class add_con
        {
        private: T const_value;
        public : add_con(T n) : const_value(n){}
                 void operator()(T& x){ x += const_value; }
        };
template <typename T>
class subs_const
        {
        private: T const_value;
        public : subs_const(T n) : const_value(n){}
                 void operator()(T& x){ x -= const_value; }
        };

template <typename T>
class div_const
        {
        private : T const_value;
        public  : div_const(T n) : const_value(n){}
                  void operator()(T& x){ x /= const_value; }
        };
template< typename T>
class eq_rand
        {
        public : void operator()(T& x){ x = rand()/(static_cast<T>(RAND_MAX) + 1.0);}
        };

template< typename T,typename Iter_T>
class Accumulasi
        {
        public :
                T operator()(Iter_T first,Iter_T last)
                        {
                        T sum = 0;
                        while( first != last )
                                {
                                sum += *first++;
                                }
                        return sum;
                        }
        };

template<typename T> class negatif { public: void operator()(T& x){ x = -x;            } };
template<typename T> class FS   { public : T   operator()(T  x){ return 1/(1+exp(-x)); } };
template<typename C> class DFS  { public : C   operator()(C  x){ return x*(1-x);       } };
template<typename C> class zeros{ public: void operator()(C& x){ x = static_cast<C>(0);} };






template <typename Value_T,int N,int M>
class ObjectNN
        {

        public:
        typedef Value_T value_type;
        typedef Value_T* iterator;
        typedef const Value_T* const_iterator;
        typedef Value_T& reference;
        typedef const Value_T& const_reference;
        typedef size_t difference_type;
        typedef ObjectNN self;


        iterator begin(){ return DataMatrix; }
        iterator end()  { return DataMatrix + N*M; }
        iterator row_begin(difference_type n){ return begin() + n*M; }
        const_iterator begin() const { return DataMatrix; }
        const_iterator end()   const { return DataMatrix + N*M; }
        const_iterator row_begin(difference_type n) const { return begin() + n*M; }
        iterator operator[](difference_type n){ return row_begin(n); }
        difference_type stepw(){ return M; }

        void  assign(iterator first,iterator last){ copy(first,last,begin()); }
        self& operator=(const self& x){ copy(x.begin(),x.end(),begin()); return *this; }
        self& operator=(value_type n){ for_each(begin(),end(),assign_const<value_type>(n)); return *this;}
        self& operator+=(value_type n){ for_each(begin(),end(),add_con<value_type>(n)); return *this; }
        self& operator+=(const self& x){
                const_iterator iter_l;
                iterator iter_r = begin();
                for( iter_l=x.begin(); iter_l != x.end(); ++iter_l,++iter_r)
                        *iter_r += *iter_l;
                return *this;
                }

        self& operator-(){ for_each(begin(),end(),negatif<value_type>()); return *this; }
        self& operator-=(value_type n){ for_each(begin(),end(),subs_const<value_type>(n)); return *this; }
        self& operator-=(const self& x){
                const_iterator iter_l;
                iterator iter_r = begin();
                for( iter_l=x.begin();iter_l != x.end(); ++ iter_l,++iter_r)
                        *iter_r -= *iter_l;
                return *this;
                }


        friend self operator+(self x,value_type n){ return x += n; }
        friend self operator+(value_type n,self x){ return x += n; }
        friend self operator-(self x,value_type n){ return x -= n; }
        friend self operator-(value_type n,self x){ return x -= n; }
        friend self operator+(self x,const self& y){ return x += y; }
        friend self operator-(self x,const self& y){ return x -= y; }


        value_type DataMatrix[N*M];
        };


const double alfa = 0.9;
double SigmoidBiner(double inp){ return 1.0/( 1.0 + exp(-inp) ); }
double diff_SigmoidBiner(double inp){ return SigmoidBiner(inp)*( 1 - SigmoidBiner(inp) ); }
void random(double& n) { n = rand()/((double)RAND_MAX + 1.0); }

template<typename T,int n_input,int n_hidden,int n_output>
class Neural_Network
        {

        // data node and weight
        ObjectNN<T,n_hidden,n_output> wHidOut;
        ObjectNN<T,n_input,n_hidden> wInpHid;
        ObjectNN<T,n_hidden,1> bHid;
        ObjectNN<T,n_output,1> bOut;
        ObjectNN<T,n_hidden,1> Hid,Hid_in;
        ObjectNN<T,n_output,1> Out,Out_in;
        ObjectNN<T,n_output,1> tar;
        ObjectNN<T,n_hidden,1> error_j;
        ObjectNN<T,n_output,1> error_k;
        ObjectNN<T,n_output,1> prereq_error;
        ObjectNN<T,n_input,1>  inp;

        public:
        typedef typename ObjectNN<T,n_output,1>::iterator iter_out;
        typedef typename ObjectNN<T,n_input,1>::iterator iter_in;
        typedef typename ObjectNN<T,n_output,1>::iterator iter_target;

        // constructor
        Neural_Network()
                {
                for_each(wInpHid.begin(),wInpHid.end(),eq_rand<T>());
                for_each(wHidOut.begin(),wInpHid.end(),eq_rand<T>());
                for_each(bHid.begin()   ,bHid.end()   ,eq_rand<T>());
                for_each(bOut.begin()   ,bOut.end()   ,eq_rand<T>());
                for_each(Hid.begin()    ,Hid.end()    ,eq_rand<T>());
                for_each(Hid_in.begin() ,Hid_in.end() ,eq_rand<T>());
                for_each(Out.begin()    ,Out.end()    ,eq_rand<T>());
                for_each(Out_in.begin() ,Out_in.end() ,eq_rand<T>());
                }






        // assign function target and input
        template<typename C>      void assign_input ( const ObjectNN<C,n_input,1>& inp_ ){ inp = inp_; }
        template<typename iter_C> void assign_input ( iter_C first,iter_C last)          { copy(first,last,inp.begin()); }
        template<typename C>      void assign_target( const ObjectNN<C,n_output,1>& tar_){ tar = tar_; }
        template<typename iter_C> void assign_target( iter_C first,iter_C last)          { copy(first,last,tar.begin()); }

        // forward step
        ObjectNN<T,n_output,1> processForward()
                {
                int step_i,step_j,step_k;
                for(step_j=0;step_j<n_hidden;++step_j){
                        Hid_in[step_j][0] = bHid[step_j][0];
                        for(step_i=0;step_i<n_input;++step_i){
                                Hid_in[step_j][0] += inp[step_i][0]*wInpHid[step_i][step_j];
                                } // end iterasi input;
                                Hid[step_j][0] = SigmoidBiner(Hid_in[step_j][0]);
                        } // end iterasi hidden

                for(step_k=0;step_k<n_output;++step_k){
                        Out_in[step_k][0] = bOut[step_k][0];
                        for(step_j=0;step_j<n_hidden;++step_j){
                                Out_in[step_k][0] += Hid[step_j][0]*wHidOut[step_j][step_k];
                                } // end iterasi hidden;
                                Out[step_k][0] = SigmoidBiner(Out_in[step_k][0]);
                        } // end iterasi output;
                return Out;
                }// end process forward

         // learning step
         void processLearn()
                {
                int step_i,step_j,step_k;
                for(step_k=0;step_k<n_output;++step_k){
                        error_k[step_k][0] = (tar[step_k][0] - Out[step_k][0]);
                        prereq_error[step_k][0] = fabs(error_k[step_k][0]);
                        error_k[step_k][0] *= diff_SigmoidBiner(Out_in[step_k][0]);
                        }

                for(step_j=0;step_j<n_hidden;++step_j){
                        error_j[step_j][0] = 0;
                        for(step_k=0;step_k<n_output;++step_k){
                                error_j[step_j][0] += error_k[step_k][0] * wHidOut[step_j][step_k];
                                }
                        error_j[step_j][0] *= diff_SigmoidBiner(Hid_in[step_j][0]);
                        }

                for(step_k=0;step_k<n_output;++step_k){
                        for(step_j=0;step_j<n_hidden;++step_j){
                                wHidOut[step_j][step_k] += alfa*error_k[step_k][0]*Hid[step_j][0];
                                }
                         bOut[step_k][0] += alfa*error_k[step_k][0];
                         }

                for(step_j=0;step_j<n_hidden;++step_j){
                        for(step_i=0;step_i<n_input;++step_i){
                                wInpHid[step_i][step_j] += alfa*error_j[step_j][0]*inp[step_i][0];
                                }
                        bHid[step_j][0] += alfa*error_j[step_j][0];
                        }
                }// end process learning

                // get last error
                ObjectNN<T,n_output,1> getPreErr(){ return prereq_error; }
                void check_success(){
                        T sum_of_error = 0;
                        for(iter_out iter = getPreErr().begin(); iter!=getPreErr().end(); ++iter) sum_of_error += *iter;
                        cout << "Sum total : " << sum_of_error << endl;
                        if( sum_of_error > 1 ) throw exception();
                        }

    }; // end class neural object





template<typename Type,typename Iter_Type>
void sumAverage(Iter_Type first,Iter_Type last,Type& result)
        {
        unsigned int count = 0;
        result = 0;
        while(first != last)
                {
                result += *first;
                first++;
                count++;
                }
       result /= count;
       }


template<typename Type>
void block_image(cv::Mat& im,std::vector<Type>& data,cv::Rect rect,int step)
        {
        if( im.channels() != 3 )
                {
                cv::Mat ip = im(rect);
                Type sum = 0;
                for(int i=0;i<ip.rows;i+=step)
                        {
                        for(int j=0;j<ip.cols;j+=step)
                                {
                                cv::Mat temp = ip(cv::Rect(i,j,step,step));
                                sumAverage<Type>(temp.begin< unsigned char>(),temp.end<unsigned char>(),sum);
                                data.push_back(sum);
                                } // end loop
                        } // end loop rows
                } // end if channels
                for_each(data.begin(),data.end(),div_const<double>(255) );
        }



template<typename T,int INP,int HID,int OUT>
void scanning_blue(cv::Mat& im,Neural_Network<T,INP,HID,OUT>& nn,cv::Rect rect,int step)
        {
        cv::Mat ip = im(rect);
        std::vector<cv::Mat> comp;
        cv::split(ip,comp);
        ObjectNN<T,INP,1> put;
        ObjectNN<T,INP,1> out;


        T sum_blue = 0;
        T d_minimum = 10;
        T d;

        int indexx;
        int indexy;
        for(int i=0;i<ip.rows;i+=step)
                {
                for(int j=0;j<ip.cols;j+=step)
                        {

                        cv::Mat blue = comp[0](cv::Rect(i,j,step,step));
                        sumAverage<T>(blue.begin<unsigned char>(),blue.end<unsigned char>(),sum_blue);

                        put[0][0] = sum_blue/255;
                        nn.assign_input(put);
                        out = nn.processForward();
                        d = abs(1-out[0][0]);

                        if( d_minimum > d ) {
                                   d_minimum = d;
                                   indexx=i;
                                   indexy=j;
                                }
                        }
                }
         int Qual = 100*(1 - sum_blue/255);
         std::string str = "Target-blue : ";
	 //+ boost::lexical_cast<std::string>(Qual);
         cv::rectangle(im,cv::Rect(indexx,indexy,step,step),cv::Scalar(0,0,255));
         cv::putText( im, str, cv::Point(indexx+step,indexy+step), CV_FONT_HERSHEY_COMPLEX, 0.5,cv::Scalar(255, 0, 0), 1, 4);


        }


template<typename T,int INP,int HID,int OUT>
void scanning_green(cv::Mat& im,Neural_Network<T,INP,HID,OUT>& nn,cv::Rect rect,int step)
        {
        cv::Mat ip = im(rect);
        std::vector<cv::Mat> comp;
        cv::split(ip,comp);
        ObjectNN<T,INP,1> put;
        ObjectNN<T,INP,1> out;


        T sum_green = 0;
        T d_minimum = 10;
        T d;

        int indexx;
        int indexy;
        for(int i=0;i<ip.rows;i+=step)
                {
                for(int j=0;j<ip.cols;j+=step)
                        {

                        cv::Mat green = comp[1](cv::Rect(i,j,step,step));
                        sumAverage<T>(green.begin<unsigned char>(),green.end<unsigned char>(),sum_green);

                        put[0][0] = sum_green/255;
                        nn.assign_input(put);
                        out = nn.processForward();
                        d = abs(1-out[0][0]);

                        if( d_minimum > d ) {
                                   d_minimum = d;

                                   indexx=i;
                                   indexy=j;
                                }
                        }
                }

         int Qual = 100*(1-sum_green/255);
         std::string str = "Target-green : ";
	 //boost::lexical_cast<std::string>(Qual);
         cv::rectangle(im,cv::Rect(indexx,indexy,step,step),cv::Scalar(0,0,255));
         cv::putText( im, str, cv::Point(indexx+step,indexy+step), CV_FONT_HERSHEY_COMPLEX, 0.5,cv::Scalar(0,255,0), 1, 4);

        }

template<typename T,int INP,int HID,int OUT>
void scanning_red(cv::Mat& im,Neural_Network<T,INP,HID,OUT>& nn,cv::Rect rect,int step)
        {
        cv::Mat ip = im(rect);
        std::vector<cv::Mat> comp;
        cv::split(ip,comp);
        ObjectNN<T,INP,1> put;
        ObjectNN<T,INP,1> out;


        T sum_red = 0;
        T d_minimum = 10;
        T d;

        int indexx;
        int indexy;
        for(int i=0;i<ip.rows;i+=step)
                {
                for(int j=0;j<ip.cols;j+=step)
                        {

                        cv::Mat red = comp[2](cv::Rect(i,j,step,step));
                        sumAverage<T>(red.begin<unsigned char>(),red.end<unsigned char>(),sum_red);

                        put[0][0] = sum_red/255;
                        nn.assign_input(put);
                        out = nn.processForward();
                        d = abs(1-out[0][0]);

                        if( d_minimum > d ) {
                                   d_minimum = d;

                                   indexx=i;
                                   indexy=j;
                                }
                        }
                }

         int Qual = 100*(1-sum_red/255);
         std::string str = "Q-red : " ;
	 //boost::lexical_cast<std::string>(Qual);
         cv::rectangle(im,cv::Rect(indexx-40,indexy-40,80,80),cv::Scalar(0,0,255));
         cv::putText( im, str, cv::Point(indexx-50,indexy+60), CV_FONT_HERSHEY_COMPLEX, 0.5,cv::Scalar(0,0,255), 1, 4);

        }


int main(int argc,char** argv)
        {

        srand(static_cast<unsigned int>(time(0)));
        cv::Mat image_1 = cv::imread("blue.jpg");



        std::vector<cv::Mat> v_1;
        cv::split(image_1,v_1);




        std::vector<double> data_blue;


        //block_image<double>(v_1[0], data_blue,cv::Rect(0,0,20,20),5);
        block_image<double>(v_1[0], data_blue,cv::Rect(0,0,30,30),5);


        ObjectNN<double,1,1> inp;
        ObjectNN<double,1,1> out;
        Neural_Network<double,1,5,1> NN_blue;
        //Neural_Network<double,1,5,1> NN_red;

        cout << endl << endl;
        cout << "Processing learn";
        for(int step=0;step<3000;++step)
                {
                std::vector<double>::iterator i1 = data_blue.begin();

                while( i1 != data_blue.end() )
                        {
                                inp[0][0] = *i1++;
                                //tar[0][0] = 1.0;
                                NN_blue.assign_input(inp);
                                NN_blue.assign_target(inp);
                                out = NN_blue.processForward();
                                NN_blue.processLearn();
                                cout << out[0][0] << endl;
                        }
                }



       //process scanning
       cv::VideoCapture Cam(-1);
       cv::Mat frame;

       cv::namedWindow("Camera Frame");
       while( cv::waitKey(33) != 27 )
                {
                Cam >> frame;
                //cv::Mat dataDisp = frame(cv::Rect(0,0,300,300));
                cv::flip(frame,frame,1);
                cv::rectangle(frame,cv::Rect(0,0,300,300),cv::Scalar(255,0,0));
                scanning_blue<double,1,5,1>(frame,NN_blue,cv::Rect(0,0,300,300),5);
                //scanning_green<double,1,5,1>(frame,NN_green,cv::Rect(0,0,300,300),5);
                //scanning_blue<double,1,5,1>(frame,NN_blue,cv::Rect(0,0,300,300),5);
                cout << endl << endl;

                //cv::imshow("Camera Frame",dataDisp);
		cv::imshow("Camera Frame",frame);
                }
        return 0;
        }
