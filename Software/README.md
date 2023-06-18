# TelescopeMirrorTester
This is an application intended to provide useful tools to perform Foucault or Wire testing on reflective telescope mirrors

## Notes on setting up the Python virtual environment

### Creating a virtual environment
To create a virtual environment, run venv.
```
python3 -m venv .venv
```

### Activating a virtual environment
```
source .venv/bin/activate
```

### Ensure pip, setuptools, and wheel are up to date
```
python3 -m pip install --upgrade pip setuptools wheel
```

### Installing packages using requirements file
```
python3 -m pip install -r requirements.txt
```

### Starting JupyterLab
Start JupyterLab using:
```
jupyter lab
```

### Leaving the virtual environment
If you want to switch projects or otherwise leave your virtual environment, simply run:
```
deactivate
```

## Notes on setting up a digital camera for use with OpenCV

### On Fedora:

Enable first the RPM Fusion Free repository to get the v4l2loopback package:
```
sudo dnf install https://download1.rpmfusion.org/free/fedora/rpmfusion-free-release-$(rpm -E %fedora).noarch.rpm
```

Not needed, but for future reference to enable the Nonfree repository, do:
```
sudo dnf install https://download1.rpmfusion.org/nonfree/fedora/rpmfusion-nonfree-release-$(rpm -E %fedora).noarch.rpm
```

Install v4l2loopback and gphoto2 rpm packages:
```
sudo dnf install v4l2loopback gphoto2
```

Check if camera is correctly detected:
```
gphoto2 --abilities
```

If the computer successfully detected the camera, add it to the device list in /dev/ directory. Run the following command:
```
sudo modprobe v4l2loopback
```

Now unmout the created camera device from the file manager.

Run the following command to start taking frames from the camera:
```
gphoto2 --stdout --capture-movie | ffmpeg -i - -vcodec rawvideo -pix_fmt yuv420p -threads 0 -f v4l2 /dev/video0
```