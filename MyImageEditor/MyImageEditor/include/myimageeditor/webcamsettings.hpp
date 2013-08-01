
#ifndef WEBCAMSETTINGS_HPP
#define WEBCAMSETTINGS_HPP

#include <QtCore\QtCore>

namespace wcs
{
	struct SWebCamSettings
	{
		SWebCamSettings(const int& f_width = 0, const int& f_height = 0) :
			m_width(f_width),
			m_height(f_height)
		{
		}

		int m_width;
		int m_height;
	};

	class CWebCamSettingsMgr
	{

	public:
		typedef QMap<QString, SWebCamSettings> mapType;

		CWebCamSettingsMgr(): m_mapOfSettings()
		{
		}

		void registerSetting(const QString& f_name, const int& f_width, const int& f_height)
		{
			m_mapOfSettings[f_name] = SWebCamSettings(f_width, f_height);
		}

		int getWidth(const QString& f_name)
		{
			return m_mapOfSettings[f_name].m_width;
		}

		int getHeight(const QString& f_name)
		{
			return m_mapOfSettings[f_name].m_width;
		}

		QStringList getAllSettings()
		{
			QStringList l_list;

			mapType::Iterator l_iter = m_mapOfSettings.begin();
			for(; l_iter != m_mapOfSettings.end() ; l_iter++)
			{
				l_list.append(l_iter.key());
			}

			return l_list;
		}

	private:
		 mapType m_mapOfSettings;
	};
}

#endif