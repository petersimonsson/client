#include "SolidColorCommand.h"

#include "Global.h"

SolidColorCommand::SolidColorCommand(QObject* parent)
    : AbstractCommand(parent),
      color(Color::DEFAULT_COLOR_NAME), transition(Mixer::DEFAULT_TRANSITION), duration(Mixer::DEFAULT_DURATION),
      tween(Mixer::DEFAULT_TWEEN), direction(Mixer::DEFAULT_DIRECTION), useAuto(Color::DEFAULT_USE_AUTO)
{
}

const QString& SolidColorCommand::getColor() const
{
    return this->color;
}

const QString& SolidColorCommand::getTransition() const
{
    return this->transition;
}

int SolidColorCommand::getDuration() const
{
    return this->duration;
}

const QString& SolidColorCommand::getDirection() const
{
    return this->direction;
}

const QString& SolidColorCommand::getTween() const
{
    return this->tween;
}

bool SolidColorCommand::getUseAuto() const
{
    return this->useAuto;
}

void SolidColorCommand::setColor(const QString& color)
{
    this->color = color;
    emit colorChanged(this->color);
}

void SolidColorCommand::setTransition(const QString& transition)
{
    this->transition = transition;
    emit transitionChanged(this->transition);
}

void SolidColorCommand::setDuration(int duration)
{
    this->duration = duration;
    emit durationChanged(this->duration);
}

void SolidColorCommand::setDirection(const QString& direction)
{
    this->direction = direction;
    emit directionChanged(this->direction);
}

void SolidColorCommand::setTween(const QString& tween)
{
    this->tween = tween;
    emit tweenChanged(this->tween);
}

void SolidColorCommand::setUseAuto(bool useAuto)
{
    this->useAuto = useAuto;
    emit useAutoChanged(this->useAuto);
}

void SolidColorCommand::readProperties(boost::property_tree::wptree& pt)
{
    AbstractCommand::readProperties(pt);

    if (pt.count(L"transition") > 0) setTransition(QString::fromStdWString(pt.get<std::wstring>(L"transition")));
    if (pt.count(L"duration") > 0) setDuration(pt.get<int>(L"duration"));
    if (pt.count(L"tween") > 0) setTween(QString::fromStdWString(pt.get<std::wstring>(L"tween")));
    if (pt.count(L"direction") > 0) setDirection(QString::fromStdWString(pt.get<std::wstring>(L"direction")));
    if (pt.count(L"color") > 0) setColor(QString::fromStdWString(pt.get<std::wstring>(L"color")));
}

void SolidColorCommand::writeProperties(QXmlStreamWriter* writer)
{
    AbstractCommand::writeProperties(writer);

    writer->writeTextElement("transition", this->getTransition());
    writer->writeTextElement("duration", QString::number(this->getDuration()));
    writer->writeTextElement("tween", this->getTween());
    writer->writeTextElement("direction", this->getDirection());
    writer->writeTextElement("color", this->getColor());
}