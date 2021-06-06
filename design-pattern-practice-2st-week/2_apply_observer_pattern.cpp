#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Observer{
public:
    void update(vector<float> temperature, vector<float> humidity, vector<float> preasure);
};

class WeatherData {
private:
    vector<float> temperature;
    vector<float> humidity;
    vector<float> preesure;
    list<Observer> observers;
public:
    WeatherData(){};
    vector<float> getTemparature(){
        return this->temperature;
    }
    vector<float> getHumidity(){
        return this->humidity;
    }
    vector<float> getPreesure(){
        return this->preesure;
    }
    void registerObserver(Observer o){
        observers.push_back(o);
    }
    void removeObserver(Observer o){
        observers.remove(o);
    }
    
    void notifyObservers(){
        list<Observer>::iterator it;
        for(it=observers.begin();it!=observers.end();it++){
            it->update(temperature, humidity, preesure);
        }
    }
    
    void measurementsChanged(){
        notifyObservers();
    }
    
    void setMonitoringData(vector<float> temperature, vector<float> humidity, vector<float> preesure){
        this->humidity = humidity;
        this->preesure = preesure;
        this->temperature = temperature;
        measurementsChanged();
    }
    
};

class WeatherDataDisplay:public Observer{
private:
    WeatherData* weatherData;
public:
    WeatherDataDisplay(){};
    WeatherDataDisplay(WeatherData* weatherData){
        this->weatherData = weatherData;
    }
    
    void update(WeatherData* weatherData){
        this->weatherData = weatherData;
        display();
    }
    
    void display(){
        //display data
    }
    
};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    WeatherData* weatherData = new WeatherData();
    vector<float> temperatureData = {10,15,12};
    vector<float> preesureData = {12, 21, 13};
    vector<float> humidityData = {21, 42, 19};
    WeatherDataDisplay weatherDataDisplay;
    weatherData->registerObserver(weatherDataDisplay);
    weatherData->setMonitoringData(temperatureData, preesureData, humidityData);
    
    return 0;
}
