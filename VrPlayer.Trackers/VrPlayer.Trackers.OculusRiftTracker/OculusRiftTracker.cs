using System;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Windows.Threading;
using System.Windows.Media.Media3D;
using OvrWrapper;
using VrPlayer.Contracts.Trackers;
using VrPlayer.Helpers;

namespace VrPlayer.Trackers.OculusRiftTracker
{
    [DataContract]
    public class OculusRiftTracker : TrackerBase, ITracker
    {
        private readonly OvrWrapper.OvrWrapper _ovrWrapper = new OvrWrapper.OvrWrapper();
        private OvrSession _ovrSession;

        private readonly DispatcherTimer _timer;
            
        public OculusRiftTracker()
        {
            _timer = new DispatcherTimer(DispatcherPriority.Send);
            _timer.Interval = new TimeSpan(0, 0, 0, 0, 15);
            _timer.Tick += timer_Tick;
        }

        public override void Load()
        {
            _ovrSession = _ovrWrapper.CreateSession();
            _ovrSession.PrintResolution();
            _timer.Start();
        }

        public override void Unload()
        {
            _timer.Stop();
            _ovrSession.Dispose();
        }

        void timer_Tick(object sender, EventArgs e)
        {
            try
            {
                var q = _ovrSession.GetTrackingState();
                if (!q.HasValue)
                {
                    return;
                }
                RawRotation = q.Value;
                UpdatePositionAndRotation();
            }
            catch(Exception exc)
            {
                Logger.Instance.Error(exc.Message, exc);
            }
        }
    }
}