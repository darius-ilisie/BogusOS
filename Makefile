iso:
	rm -f iso_root/bogus.elf
	cp -v kernel/bogus.elf iso_root/
	xorriso -as mkisofs -b limine-cd.bin -no-emul-boot -boot-load-size 4 -boot-info-table --efi-boot limine-cd-efi.bin -efi-boot-part --efi-boot-image --protective-msdos-label iso_root -o image.iso
	./limine/limine-deploy image.iso

clean:
	rm -f image.iso