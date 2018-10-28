FROM rhargreaves/gendev:manual-1.0.1
RUN apt-get -y update && \
	apt-get -y install \
		build-essential \
		cmake
