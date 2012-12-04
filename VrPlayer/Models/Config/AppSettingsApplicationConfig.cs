﻿using System.Configuration;

namespace VrPlayer.Models.Config
{
    public class AppSettingsApplicationConfig : IApplicationConfig
    {
        public AppSettingsApplicationConfig()
        {
            _defaultMediaFile = ConfigurationManager.AppSettings["DefaultMediaFile"];
            _customPincushionFactor = double.Parse(ConfigurationManager.AppSettings["CustomPincushionFactor"]);
            _cameraFieldOfView = int.Parse(ConfigurationManager.AppSettings["CameraFieldOfView"]);
            _mouseSensitivity = int.Parse(ConfigurationManager.AppSettings["MouseSensitivity"]);
        }

        private string _defaultMediaFile;
        public string DefaultMediaFile
        {
            get { return _defaultMediaFile; }
        }

        private double _customPincushionFactor;
        public double CustomPincushionFactor
        {
            get { return _customPincushionFactor; }
        }

        private int _cameraFieldOfView;
        public int CameraFieldOfView
        {
            get { return _cameraFieldOfView; }
        }

        private int _mouseSensitivity;
        public int MouseSensitivity
        {
            get { return _mouseSensitivity; }
        }
    }
}
