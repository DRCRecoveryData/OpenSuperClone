#!/bin/sh

[ ! -d build ] && mkdir build

echo "Configuring..."
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/ $@

if [ $? -ne 0 ]; then
    echo "CMake failed. Aborting."
    exit 1
else
    echo "CMake succeeded."
fi

if [ -z "$THREADS" ]; then
    THREADS=$(grep -c ^processor /proc/cpuinfo 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 1)
fi

echo "Building with $THREADS threads..."
cd build
make -j$THREADS

if [ $? -ne 0 ]; then
    echo "Build failed. Aborting."
    exit 1
else
    echo "Build succeeded."
fi

echo "Installing OpenSuperClone to /usr/..."
sudo make install

if [ $? -ne 0 ]; then
    echo "Install failed. Aborting."
    exit 1
else
    echo "Install succeeded."
fi

VERSION=$(grep -oP '(?<=set\(OSC_DRIVER_VERSION ).*(?=\))' ../CMakeLists.txt)
echo "Found OSCDriver version $VERSION."

echo "Adding OSCDriver to DKMS..."
sudo dkms add -m oscdriver/$VERSION

if [ $? -ne 0 ]; then
    echo "Failed to add OSCDriver to DKMS."
else
    echo "Added OSCDriver to DKMS."
fi

echo "Building OSCDriver..."
sudo dkms build -m oscdriver -v $VERSION

if [ $? -ne 0 ]; then
    echo "Failed to build OSCDriver."
else
    echo "Built OSCDriver."
fi

echo "Installing OSCDriver..."
sudo dkms install -m oscdriver -v $VERSION

if [ $? -ne 0 ]; then
    echo "Failed to install OSCDriver."
else
    echo "Installed OSCDriver."
fi

echo "Loading OSCDriver..."
sudo modprobe oscdriver

if [ $? -ne 0 ]; then
    echo "Failed to load OSCDriver."
    exit 1
else
    echo "Loaded OSCDriver."
fi

echo "Disabling OSCDriver from loading on boot..."
sudo sh -c 'echo "blacklist oscdriver" > /etc/modprobe.d/oscdriver.conf'

if [ $? -ne 0 ]; then
    echo "Failed to disable OSCDriver from loading on boot."
    exit 1
else
    echo "Disabled OSCDriver from loading on boot."
fi

echo "Done."