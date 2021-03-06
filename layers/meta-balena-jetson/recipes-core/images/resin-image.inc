IMAGE_FSTYPES_append = " resinos-img"

do_rootfs_resinos-img_jetson-nano[depends] += " tegra210-flash:do_deploy \
                                                virtual/kernel:do_deploy \
"

DTBFILE ?= "${@os.path.basename(d.getVar('KERNEL_DEVICETREE', True).split()[0])}"
DTBFILE_jn30b-nano = "tegra210-p3448-0002-p3449-0000-b00-jn30b-JP4.2.2.dtb"

# Name update files as partition names for easier updating
RESIN_BOOT_PARTITION_FILES_jetson-nano = " \
    bootfiles/nvtboot_cpu.bin.encrypt:/bootfiles/TBC \
    bootfiles/${DTBFILE}.encrypt:/bootfiles/RP1 \
    bootfiles/cboot.bin.encrypt:/bootfiles/EBT \
    bootfiles/warmboot.bin.encrypt:/bootfiles/WB0 \
    bootfiles/sc7entry-firmware.bin.encrypt:/bootfiles/BPF \
    bootfiles/tos-mon-only.img.encrypt:/bootfiles/TOS \
    bootfiles/eks.img:/bootfiles/EKS \
    bootfiles/u-boot-dtb.bin.encrypt:/bootfiles/LNX \
    bootfiles/${DTBFILE}.encrypt:/bootfiles/DTB \
    bootfiles/rp4.blob:/bootfiles/RP4 \
    bootfiles/bmp.blob:/bootfiles/BMP \
"

do_rootfs_resinos-img_jetson-xavier[depends] += " tegra194-flash-dry:do_deploy "

RESIN_BOOT_PARTITION_FILES_jetson-xavier = " \
    bootfiles/mb1_t194_prod_sigheader.bin.encrypt:/bootfiles/mb1_t194_prod_sigheader.bin.encrypt \
    bootfiles/spe_t194_sigheader.bin.encrypt:/bootfiles/spe_t194_sigheader.bin.encrypt \
    bootfiles/nvtboot_t194_sigheader.bin.encrypt:/bootfiles/nvtboot_t194_sigheader.bin.encrypt \
    bootfiles/preboot_c10_prod_cr_sigheader.bin.encrypt:/bootfiles/preboot_c10_prod_cr_sigheader.bin.encrypt \
    bootfiles/slot_metadata.bin:/bootfiles/slot_metadata.bin \
    bootfiles/bmp.blob:/bootfiles/bmp.blob \
    bootfiles/mce_c10_prod_cr_sigheader.bin.encrypt:/bootfiles/mce_c10_prod_cr_sigheader.bin.encrypt \
    bootfiles/mts_c10_prod_cr_sigheader.bin.encrypt:/bootfiles/mts_c10_prod_cr_sigheader.bin.encrypt \
    bootfiles/cboot_t194_sigheader.bin.encrypt:/bootfiles/cboot_t194_sigheader.bin.encrypt \
    bootfiles/tos-trusty_t194_sigheader.img.encrypt:/bootfiles/tos-trusty_t194_sigheader.img.encrypt \
    bootfiles/eks_sigheader.img.encrypt:/bootfiles/eks_sigheader.img.encrypt \
    bootfiles/bpmp_t194_sigheader.bin.encrypt:/bootfiles/bpmp_t194_sigheader.bin.encrypt \
    bootfiles/tegra194-a02-bpmp-p2888-a04_sigheader.dtb.encrypt:/bootfiles/tegra194-a02-bpmp-p2888-a04_sigheader.dtb.encrypt \
    bootfiles/xusb_sil_rel_fw:/bootfiles/xusb_sil_rel_fw \
    bootfiles/camera-rtcpu-rce_sigheader.img.encrypt:/bootfiles/camera-rtcpu-rce_sigheader.img.encrypt \
    bootfiles/adsp-fw_sigheader.bin.encrypt:/bootfiles/adsp-fw_sigheader.bin.encrypt \
    bootfiles/warmboot_t194_prod_sigheader.bin.encrypt:/bootfiles/warmboot_t194_prod_sigheader.bin.encrypt \
    bootfiles/boot_sigheader.img.encrypt:/bootfiles/boot_sigheader.img.encrypt \
    bootfiles/tegra194-p2888-0001-p2822-0000-rootA_sigheader.dtb.encrypt:/bootfiles/tegra194-p2888-0001-p2822-0000-rootA_sigheader.dtb.encrypt \
    bootfiles/tegra194-p2888-0001-p2822-0000-rootB_sigheader.dtb.encrypt:/bootfiles/tegra194-p2888-0001-p2822-0000-rootB_sigheader.dtb.encrypt \
    tegra-binaries/partition_specification194.txt:/bootfiles/partition_specification194.txt \
"

do_rootfs_resinos-img_jetson-tx2[depends] += " tegra186-flash-dry:do_deploy \
                                               virtual/kernel:do_deploy \
"

RESIN_BOOT_PARTITION_FILES_jetson-tx2 = " \
    ${KERNEL_IMAGETYPE}${KERNEL_INITRAMFS}-${MACHINE}.bin:/${KERNEL_IMAGETYPE} \
    boot/extlinux.conf:/extlinux/extlinux.conf \
"

# The space resinOS takes will amount to 1GiB
IMAGE_ROOTFS_SIZE = "487424"

# Need space for all the above signed update binaries
RESIN_BOOT_SIZE_jetson-nano = "80960"
RESIN_BOOT_SIZE_jetson-xavier = "121440"
RESIN_BOOT_SIZE_jetson-tx2="80960"

PARTITION_TABLE_TYPE = "gpt"

IMAGE_INSTALL_append_jetson-nano = " \
    tegra210-flash \
    tegra-nvpmodel \
    tegra-configs-nvstartup \
    tegra-configs-udev \
"

IMAGE_INSTALL_append_jetson-xavier = " \
    tegra194-flash-dry \
    fan-startup \
    parted \
    gptfdisk \
    tegra-nvpmodel \
    tegra-configs-nvstartup \
    tegra-configs-udev \
"

IMAGE_INSTALL_append_jetson-tx2 = " \
    tegra186-flash-dry \
    parted \
    gptfdisk \
    fan-startup \
    tegra-nvpmodel \
    tegra-configs-nvstartup \
    tegra-configs-udev \
    tegra-firmware-brcm \
    tegra-brcm-patchram \
    linux-firmware-bcm4354 \
    tegra-firmware-xusb \
    bt-scripts \
"
