#include "Time_.h"

Time_::Time_()
{
    hour = ((time(0) + 3 * 3600) % (24 * 3600)) / 3600; // (time(0) + 3 * 3600) - изначально врем€ gmt, а так-как мы находимс€ в ”краине(gmt+3) мы добавл€ем 3 часа 
    minutes = (time(0) % 3600) / 60;
    seconds= (time(0) % 3600) % 60;
    format = true;
}

Time_::Time_(int hour, int minutes, int seconds, bool format)
{
    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;
    this->format = format;
}

Time_::Time_(const Time_& obj)
{
    this->minutes = obj.minutes;
    this->hour = obj.hour;
    this->seconds = obj.seconds;
    this->format = obj.format;
}

Time_& Time_::operator=(const Time_& obj)
{
    this->minutes = obj.minutes;
    this->hour = obj.hour;
    this->seconds = obj.seconds;
    this->format = obj.format;
    return *this;
}

void Time_::setHour(int hour)
{
    this->hour=hour;
}

int Time_::getHour() const
{
    return hour;
}

void Time_::setMinutes(int minutes)
{
    this->minutes = minutes;
}

int Time_::getMinutes() const
{
    return minutes;
}

void Time_::setSeconds(int seconds)
{
    this->seconds = seconds;
}

int Time_::getSeconds() const
{
    return seconds;
}

void Time_::setFormat(bool format)
{
    this->format = format;
}

bool Time_::getFormat() const
{
    return format;
}

bool Time_::valid() const
{
    if ((hour < 24 && hour >= 0) && (minutes >= 0 && minutes < 60) && (seconds >= 0 && seconds < 60))
    {
        return true;
    }
    return false;
}

void Time_::tickTime()
{
    int tick = time(0);
    while (true)
    {
        if(time(0)==tick+1)
        {
            seconds++;
            if(valid()==false)
            {
                if (seconds >= 60)
                {
                    seconds = 0;
                    minutes++;
                }
                if (minutes >= 60)
                {
                    minutes = 0;
                    hour++;
                }
                if (hour==24)
                {
                    hour = 0;
                }

            }
            return;
        }
    }
}

void Time_::untickTime()
{
    int tick = time(0);
    while (true)
    {
        if (tick+1 == time(0))
        {
            seconds--;
            if (valid() == false)
            {
                if (hour > 0)
                {
                    if (minutes > 0)
                    {
                        minutes--;
                        seconds = 59;
                    }
                    else
                    {
                        hour--;
                        minutes = 59;
                        seconds = 59;
                    }
                }
                else if (minutes > 0)
                {
                    minutes--;
                    seconds = 59;
                }
                return;
            }
        }
    }
}

void Time_::showTime() const
{
    cout << hour / 10 << hour % 10 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10;
}

bool Time_::operator==(const Time_& obj) const&
{
    if (seconds == obj.getSeconds() && minutes == obj.getMinutes() && hour == obj.getHour())
    {
        return true;
    }
    return false;
}

bool Time_::operator!=(const Time_& obj) const&
{
    if (seconds == obj.getSeconds() && minutes == obj.getMinutes() && hour == obj.getHour())
    {
        return false;
    }
    return true;
}

bool Time_::operator>(const Time_& obj) const&
{
    if ((hour * 3600 + minutes * 60 + seconds) > (obj.getHour() * 3600 + obj.getMinutes() * 60 + obj.getSeconds()))
    {
        return true;
    }
    return false;
}

bool Time_::operator<(const Time_& obj) const&
{
    if ((hour * 3600 + minutes * 60 + seconds) > (obj.getHour() * 3600 + obj.getMinutes() * 60 + obj.getSeconds()))
    {
        return false;
    }
    return true;
}

bool Time_::operator>=(const Time_& obj) const&
{
    if ((hour * 3600 + minutes * 60 + seconds) >= (obj.getHour() * 3600 + obj.getMinutes() * 60 + obj.getSeconds()))
    {
        return true;
    }
    return false;
}

bool Time_::operator<=(const Time_& obj) const&
{
    if ((hour * 3600 + minutes * 60 + seconds) >= (obj.getHour() * 3600 + obj.getMinutes() * 60 + obj.getSeconds()))
    {
        return false;
    }
    return true;
}

Time_& Time_::operator+=(int s)
{
    
}

Time_& Time_::operator-=(int s)
{
    // TODO: вставьте здесь оператор return
}

Time_& Time_::operator+=(float m)
{
    // TODO: вставьте здесь оператор return
}

Time_& Time_::operator-=(float m)
{
    // TODO: вставьте здесь оператор return
}

Time_& Time_::operator+=(long h)
{
    // TODO: вставьте здесь оператор return
}

Time_& Time_::operator-=(long h)
{
    // TODO: вставьте здесь оператор return
}

Time_ Time_::operator+(int s) const&
{
    return Time_();
}

Time_ Time_::operator-(int s) const&
{
    return Time_();
}

Time_ Time_::operator+(float m) const&
{
    return Time_();
}

Time_ Time_::operator-(float m) const&
{
    return Time_();
}

Time_ Time_::operator+(long h) const&
{
    return Time_();
}

Time_ Time_::operator-(long h) const&
{
    return Time_();
}
